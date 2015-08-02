/*
 * this code is based on TI-5x emulator
 * (c) 2014 Hynek Sladky
 * http://hsl.wz.cz/ti_59.htm
 */

#ifndef TI59_H
#define TI59_H


class CPObject;
class Ctmc0501;
class Cconnector;

#include "pcxxxx.h"
#include "modelids.h"


class Cti59 : public CpcXXXX
{
    Q_OBJECT

public:
    Cti59(CPObject *parent=0,Models mod=TI59);
    virtual ~Cti59();

    virtual bool	Chk_Adr(UINT32 *d,UINT32 data);
    virtual bool	Chk_Adr_R(UINT32 *d, UINT32 *data);
    virtual UINT8 in(UINT8 address);
    virtual UINT8 out(UINT8 address,UINT8 value);

    virtual bool	Set_Connector(Cbus *_bus = 0);
    virtual bool	Get_Connector(Cbus *_bus = 0);

    quint16 kstrobe;

    bool init();
    virtual bool run();
    virtual void Reset();

    void TurnON();
    void TurnOFF();
    bool SaveConfig(QXmlStreamWriter *xmlOut);
    bool LoadConfig(QXmlStreamReader *xmlIn);

    UINT8 getKey();

    Ctmc0501 *ti59cpu;

    QString Display();
private:
    Models currentModel;
};

#endif // TI59_H

