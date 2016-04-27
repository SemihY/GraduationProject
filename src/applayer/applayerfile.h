/*
 * applayerfile.h
 *
 *  Created on: 13 Mar 2016
 *      Author: 5537
 */

#ifndef APPLAYERFILE_H_
#define APPLAYERFILE_H_

#include "BaseWaveApplLayer.h"
#include "modules/mobility/traci/TraCIMobility.h"
#include <messageFile.h>

using Veins::TraCIMobility;
using Veins::AnnotationManager;

/**
 * Small IVC Demo using 11p
 */
class applayerfile : public BaseWaveApplLayer {
    public:
        virtual void initialize(int stage);
        virtual void receiveSignal(cComponent* source, simsignal_t signalID, cObject* obj);
    protected:
        TraCIMobility* traci;
        AnnotationManager* annotations;
        simtime_t lastDroveAt;
        std::priority_queue<int>  NB_FRONT,NB_BACK,NB_OPPOSITE,FORPRINTING;
        bool sentBeacon;
        bool sentMessage;
    protected:
        virtual void onBeacon(WaveShortMessage* wsm);
        virtual void onData(WaveShortMessage* wsm);
        void onMyBeacon(messageFile* wsm);
        void onMyMessage(messageFile* wsm);
        void send_WSM(messageFile* wsm);
        void send_Message(messageFile* wsm);
        void neigbors_tables(Coord position,int senderId);
        virtual void handlePositionUpdate(cObject* obj);
        messageFile*  preparemyWSM(std::string name, int lengthBits, t_channel channel, int priority, int rcvId, int serial);
        virtual void handleLowerMsg(cMessage* msg);
        void handleSelfMsg(cMessage* msg);

        messageFile* sentMessageEvt;
};

#endif
