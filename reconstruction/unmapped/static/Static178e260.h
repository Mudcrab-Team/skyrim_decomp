// Source exposure: binary-analysis; no external implementation source reused.
// Static178e260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178e260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178e260*);
    virtual void release(Static178e260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178e260*);
struct Static178e260 {
    void* value;
    Static178e260();
    ~Static178e260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
