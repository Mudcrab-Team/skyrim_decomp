// Source exposure: binary-analysis; no external implementation source reused.
// Static178a000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a000*);
    virtual void release(Static178a000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a000*);
struct Static178a000 {
    void* value;
    Static178a000();
    ~Static178a000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
