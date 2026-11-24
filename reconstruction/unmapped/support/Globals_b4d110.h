// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// hkpEntity: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpEntity::applyLinearImpulseAsCriticalOperation_140A6E850: CRASHLOGGER_PDB(59818@2026.10.24)
// padding_0_, padding_18_, vslot_0_, vslot_1_, vslot_2_, vslot_3_, vslot_4_, vslot_5_, vslot_6_, vslot_7_, vslot_8_, vslot_9_, vslot_10_, vslot_11_, vslot_12_, vslot_13_, vslot_14_, vslot_15_, vslot_16_, vslot_17_, vslot_18_: GUESS(low); placeholder name
// Globals: GUESS(low); placeholder name
#pragma once

__declspec(align(16)) int unk00;
extern const double Data00db88e8;

namespace f3m_0090cf80 {
namespace vector_event_0090cf80 {
struct Event;
struct Manager;
struct Point3;

struct Array {unsigned table;void* data;unsigned short capacity,count,u0c,grow;unsigned Count()const{return count;}unsigned Capacity()const{return capacity;}unsigned Grow()const{return grow;}void Func00555790(unsigned);void Func005b3880(unsigned,void**);void Append(void* value){unsigned n=Count();if(n>=Capacity())Func00555790(n+Grow());Func005b3880(n,&value);}};

struct Vector {float x,y,z;void* Func00823dc0(unsigned*);Vector Scaled()const{Vector v;v.x=(float)(x*Data00db88e8);v.y=(float)(y*Data00db88e8);v.z=(float)(z*Data00db88e8);return v;}};


struct hkpEntity;
struct Point3 {
    float x,y,z;
    inline Point3(const Point3& source) : x(source.x),y(source.y),z(source.z) {}
};
struct Event {
    unsigned char type;
    hkpEntity* source;
    Point3 value;
    inline Event(hkpEntity* owner,const Point3& point) : type(0x1c),source(owner),value(point) {}
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct Manager
{
  public:
    char padding_0_[248];
    unsigned int active;
    void Func00902570(const Event*);
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct EmbeddedInterface
{
  public:
    virtual void vslot_0_();
    virtual void vslot_1_();
    virtual void vslot_2_();
    virtual void vslot_3_();
    virtual void vslot_4_();
    virtual void vslot_5_();
    virtual void vslot_6_();
    virtual void vslot_7_();
    virtual void vslot_8_();
    virtual void vslot_9_();
    virtual void vslot_10_();
    virtual void vslot_11_();
    virtual void vslot_12_();
    virtual void vslot_13_();
    virtual void vslot_14_();
    virtual void vslot_15_();
    virtual void vslot_16_();
    virtual void vslot_17_();
    virtual void vslot_18_();
    virtual void Notify(const Point3&);
};
// Stand-in layout: the members and virtual slots the function uses, at the target offsets; the padding is a guess.
struct hkpEntity
{
  public:
    char padding_0_[16];
    Manager *manager;
    char padding_18_[312];
    EmbeddedInterface fallback;
    void Func0090b500();
    void applyLinearImpulseAsCriticalOperation_140A6E850(const Point3&);
};
}
}

struct Globals
{
};
