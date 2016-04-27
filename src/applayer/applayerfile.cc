/*
 * applayerfile.cc
 *
 *  Created on: 13 Mar 2016
 *      Author: 5537
 */

#include "applayerfile.h"

using Veins::TraCIMobilityAccess;
using Veins::AnnotationManagerAccess;

Define_Module(applayerfile);

void applayerfile::initialize(int stage) {
    BaseWaveApplLayer::initialize(stage);
    if (stage == 0) {
        traci = TraCIMobilityAccess().get(getParentModule());
        annotations = AnnotationManagerAccess().getIfExists();
        ASSERT(annotations);

        lastDroveAt = simTime();

        if(myId==4){
            EV <<"SenderId "<<myId<<endl;
            sentMessageEvt = preparemyWSM("message", beaconLengthBits, type_CCH, beaconPriority, 0, -1);
            scheduleAt(simTime(), sentMessageEvt);
        }

        EV << " Deneme App Layer "<< endl;
    }
    if(stage==1){
        // Ini den sonra
        traci->getAngleRad()
    }
}

void applayerfile::receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj) {
    Enter_Method_Silent();
    if (signalID == mobilityStateChangedSignal) {
        EV << "receive message\n";
        handlePositionUpdate(obj);
    }
}
void applayerfile::handlePositionUpdate(cObject* obj) {
    BaseWaveApplLayer::handlePositionUpdate(obj);

}

void applayerfile::onBeacon(WaveShortMessage* wsm) {
    EV << "Deneme";

}

void applayerfile::onData(WaveShortMessage* wsm){

   // EV <<"Road ID" << traci->getRoadId() << endl;
}

void applayerfile::onMyBeacon(messageFile* wsm) {

        EV <<"My Position x:"<<traci->getCurrentPosition().x<<"My Position y:"<<traci->getCurrentPosition().y<<"My Position z:"<<traci->getCurrentPosition().z<<endl;
        EV <<"Sender Position x:"<<wsm->getSenderPos().x<<"Sender Position y:"<<wsm->getSenderPos().y<<"Sender Position z:"<<wsm->getSenderPos().z<<"Sender id: "<<wsm->getSenderAddress()<<endl;
       Coord lowerBound =Coord(traci->getCurrentPosition().x-55,traci->getCurrentPosition().y-25);
       Coord upperBound =Coord(traci->getCurrentPosition().x+55,traci->getCurrentPosition().y+25);
        if(lowerBound.x <= wsm->getSenderPos().x && wsm->getSenderPos().x <= upperBound.x &&
           lowerBound.y <= wsm->getSenderPos().y && wsm->getSenderPos().y <= upperBound.y){
           neigbors_tables(wsm->getSenderPos(),wsm->getSenderAddress());
       }
}

void applayerfile::onMyMessage(messageFile* wsm) {
    EV <<"Destination"<<wsm->getDestination()<<"Recipient Adress"<<wsm->getRecipientAddress()<<"My Id"<<myId<<endl;
    if(wsm->getDestination()==myId){ // DFlg equals 1
        bubble("Mesaj hedefe ulasti");
    }
    else if(wsm->getRecipientAddress()==myId){
        send_Message(wsm);
    }


}
void applayerfile::neigbors_tables(Coord Position,int senderId){

    EV<<"**********Mesaj geldi MyId:"<< getParentModule()->getIndex() <<" SenderId:"<< senderId <<endl;
    EV <<"My Position x:"<<traci->getCurrentPosition().x<<endl;
    EV <<"Sender Position x:"<<Position.x<<"Sender id: "<<senderId<<endl;
    if(traci->getCurrentPosition().y>5 && 1!=1) {// to understand which lane if y is greater than 5 , car is travelling through the left side
        if(Position.y<5){
            EV <<"ID"<<getParentModule()->getIndex()<<"NBOPPOSITE"<<senderId<<endl;
            NB_OPPOSITE.push(senderId);
        }else{
            if(Position.x<traci->getCurrentPosition().x){
                EV <<"ID "<<getParentModule()->getIndex()<<" NBFRONT "<<senderId<<endl;
             NB_FRONT.push(senderId);
            }
            if(Position.x>traci->getCurrentPosition().x){
                EV <<"ID"<<getParentModule()->getIndex()<<" NBBACK "<<senderId<<endl;
             NB_BACK.push(senderId);
            }
        }
    }else{        // car is travelling through the right side
        if(Position.y>5 && 1!=1){
            EV <<"ID"<<getParentModule()->getIndex()<<" NBOPPOSITE "<<senderId<<endl;
            if(NB_OPPOSITE.size()==5){ // For ensuring five of stack size
                NB_OPPOSITE.pop();
            }
            NB_OPPOSITE.push(senderId);
        }else{
            if(Position.x>traci->getCurrentPosition().x){
                EV <<"ID "<<getParentModule()->getIndex()<<" NBFRONT "<<senderId<<endl;
                if(NB_OPPOSITE.size()==5){ // For ensuring five of stack size
                  NB_OPPOSITE.pop();
                }
                NB_FRONT.push(senderId);
            }
            if(Position.x<traci->getCurrentPosition().x){
                EV <<"ID"<<getParentModule()->getIndex()<<" NBBACK "<<senderId<<endl;
                if(NB_OPPOSITE.size()==5){ // For ensuring five of stack size
                 NB_OPPOSITE.pop();
                }
             NB_BACK.push(senderId);
            }
        }
    }

    // TEST




}



messageFile*  applayerfile::preparemyWSM(std::string name, int lengthBits, t_channel channel, int priority, int rcvId, int serial) {
    messageFile* wsm = new messageFile(name.c_str(),0);
    wsm->addBitLength(headerLength);
    wsm->addBitLength(lengthBits);

    switch (channel) {
        case type_SCH: wsm->setChannelNumber(Channels::SCH1); break; //will be rewritten at Mac1609_4 to actual Service Channel. This is just so no controlInfo is needed
        case type_CCH: wsm->setChannelNumber(Channels::CCH) ; break;
    }
    wsm->setPsid(0);
    wsm->setPriority(priority);
    wsm->setWsmVersion(1);
    wsm->setTimestamp(simTime());
    wsm->setSenderAddress(myId);
    wsm->setSenderPos(curPosition);
    wsm->setRoi(Coord(curPosition.x+50,curPosition.y+50));


    wsm->setSerial(serial);

    if (name == "beacon") {
        DBG << "Creating Beacon with Priority " << priority << " at Applayer at " << wsm->getTimestamp() << std::endl;
    }
    if (name == "data") {
        DBG << "Creating Data with Priority " << priority << " at Applayer at " << wsm->getTimestamp() << std::endl;
    }
    if (name == "message") {
            bubble("Setting destination as 1");
            EV<<"Setting Destination as 1 "<<endl;

            wsm->setKind(3);
            wsm->setDestination(1);
        }

    wsm->setId(getParentModule()->getIndex());

    return wsm;
}



void applayerfile::handleLowerMsg(cMessage* msg) {

    messageFile* wsm = dynamic_cast<messageFile*>(msg);
    ASSERT(wsm);
    EV << "handleLowerMsg" << endl;
    if (std::string(wsm->getName()) == "beacon") {
        onMyBeacon(wsm);
    }
    else if (std::string(wsm->getName()) == "message") {
        onMyMessage(wsm);
    }
    else {
        DBG << "unknown message (" << wsm->getName() << ")  received\n";
    }
    delete(msg);
}

void applayerfile::handleSelfMsg(cMessage* msg) {
    EV<<"** Self message "<<endl;
    switch (msg->getKind()) {
        case SEND_BEACON_EVT: {
            send_WSM(preparemyWSM("beacon", beaconLengthBits, type_CCH, beaconPriority, 0, -1));
            scheduleAt(simTime() + par("beaconInterval").doubleValue(), sendBeaconEvt);
            break;
        }
        case 3: {
            send_Message(sentMessageEvt);
            EV<<"Hata burda"<<endl;
            scheduleAt(simTime(),sentMessageEvt);
            break;
        }

        default: {
            if (msg)
                DBG << "APP: Error: Got Self Message of unknown kind! Name: " << msg->getName() << endl;
            break;
        }
    }
}


void applayerfile::send_WSM(messageFile* wsm) {
    sendDelayedDown(wsm,individualOffset);
}
void applayerfile::send_Message(messageFile* wsm) {
    if(!NB_FRONT.empty()){        // MDC equals 1
       EV<<"Mesaji yolladim : "<<NB_FRONT.top()<<endl;
       wsm->setRecipientAddress(NB_FRONT.top());
       sendDelayedDown(wsm,individualOffset);
    }
    else{
        if(!NB_OPPOSITE.empty()){ // ODC equals 1
           EV<<"Mesaji yolladim : "<<NB_OPPOSITE.top()<<endl;
           wsm->setRecipientAddress(NB_OPPOSITE.top());
           sendDelayedDown(wsm,individualOffset);
        }
    }
}



