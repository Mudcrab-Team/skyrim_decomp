// Source exposure: binary-analysis; no external implementation source reused.
// Static178a950, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a950;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a950*);
    virtual void release(Static178a950*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a950*);
struct Static178a950 {
    void* value;
    Static178a950();
    ~Static178a950() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
