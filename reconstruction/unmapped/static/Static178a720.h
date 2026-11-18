// Source exposure: binary-analysis; no external implementation source reused.
// Static178a720, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a720;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a720*);
    virtual void release(Static178a720*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a720*);
struct Static178a720 {
    void* value;
    Static178a720();
    ~Static178a720() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
