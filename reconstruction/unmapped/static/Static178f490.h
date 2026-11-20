// Source exposure: binary-analysis; no external implementation source reused.
// Static178f490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f490*);
    virtual void release(Static178f490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f490*);
struct Static178f490 {
    void* value;
    Static178f490();
    ~Static178f490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
