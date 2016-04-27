/*
 * messageFile.h
 *
 *  Created on: 13 Mar 2016
 *      Author: 5537
 */

#ifndef MESSAGEFILE_H_
#define MESSAGEFILE_H_
#include <omnetpp.h>

#endif

// cplusplus {{
#include "WaveShortMessage_m.h"
#include "Coord.h"
// }}



/**
 * Class generated from <tt>message/messageNew.msg</tt> by opp_msgc.
 * <pre>
 * packet messageNew extends WaveShortMessage  {
 *     int id;
 * }
 * </pre>
 */
class messageFile : public ::WaveShortMessage
{
  protected:
    int id_var;
    Coord roi;
    int destination;

  private:
    void copy(const messageFile& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const messageFile&);

  public:
    messageFile(const char *name=NULL, int kind=0);
    messageFile(const messageFile& other);
    virtual ~messageFile();
    messageFile& operator=(const messageFile& other);
    virtual messageFile *dup() const {return new messageFile(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getId() const;
    virtual void setId(int id);


    virtual int getDestination() const;
    virtual void setDestination(int id);

    virtual int getRoi() const;
    virtual void setRoi(Coord id);
};

inline void doPacking(cCommBuffer *b, messageFile& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, messageFile& obj) {obj.parsimUnpack(b);}

