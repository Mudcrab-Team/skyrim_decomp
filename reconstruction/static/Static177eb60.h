// Source exposure: binary-analysis; no external implementation source reused.
// Static177eb60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177eb60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177eb60*);
    virtual void release(Static177eb60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177eb60*);
struct Static177eb60 {
    void* value;
    Static177eb60();
    ~Static177eb60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
