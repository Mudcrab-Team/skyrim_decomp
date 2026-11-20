// Source exposure: binary-analysis; no external implementation source reused.
// Static178e060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e060*);
    virtual void release(Static178e060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e060*);
struct Static178e060 {
    void* value;
    Static178e060();
    ~Static178e060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
