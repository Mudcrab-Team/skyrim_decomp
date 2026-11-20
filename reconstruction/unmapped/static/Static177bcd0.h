// Source exposure: binary-analysis; no external implementation source reused.
// Static177bcd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177bcd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177bcd0*);
    virtual void release(Static177bcd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177bcd0*);
struct Static177bcd0 {
    void* value;
    Static177bcd0();
    ~Static177bcd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
