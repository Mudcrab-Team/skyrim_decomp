// Source exposure: binary-analysis; no external implementation source reused.
// Static178a770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a770*);
    virtual void release(Static178a770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a770*);
struct Static178a770 {
    void* value;
    Static178a770();
    ~Static178a770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
