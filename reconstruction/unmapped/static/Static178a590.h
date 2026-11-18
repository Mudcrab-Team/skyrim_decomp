// Source exposure: binary-analysis; no external implementation source reused.
// Static178a590, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a590;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a590*);
    virtual void release(Static178a590*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a590*);
struct Static178a590 {
    void* value;
    Static178a590();
    ~Static178a590() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
