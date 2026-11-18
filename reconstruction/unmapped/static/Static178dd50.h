// Source exposure: binary-analysis; no external implementation source reused.
// Static178dd50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178dd50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178dd50*);
    virtual void release(Static178dd50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178dd50*);
struct Static178dd50 {
    void* value;
    Static178dd50();
    ~Static178dd50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
