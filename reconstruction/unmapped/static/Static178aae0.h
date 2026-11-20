// Source exposure: binary-analysis; no external implementation source reused.
// Static178aae0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178aae0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178aae0*);
    virtual void release(Static178aae0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178aae0*);
struct Static178aae0 {
    void* value;
    Static178aae0();
    ~Static178aae0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
