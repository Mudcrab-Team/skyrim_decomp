// Source exposure: binary-analysis; no external implementation source reused.
// Static178c920, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c920;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c920*);
    virtual void release(Static178c920*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c920*);
struct Static178c920 {
    void* value;
    Static178c920();
    ~Static178c920() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
