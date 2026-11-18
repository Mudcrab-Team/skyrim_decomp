// Source exposure: binary-analysis; no external implementation source reused.
// Static17aa290, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17aa290;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17aa290*);
    virtual void release(Static17aa290*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17aa290*);
struct Static17aa290 {
    void* value;
    Static17aa290();
    ~Static17aa290() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
