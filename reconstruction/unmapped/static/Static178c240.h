// Source exposure: binary-analysis; no external implementation source reused.
// Static178c240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c240*);
    virtual void release(Static178c240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c240*);
struct Static178c240 {
    void* value;
    Static178c240();
    ~Static178c240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
