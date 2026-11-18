// Source exposure: binary-analysis; no external implementation source reused.
// Static177d620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d620*);
    virtual void release(Static177d620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d620*);
struct Static177d620 {
    void* value;
    Static177d620();
    ~Static177d620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
