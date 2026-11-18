// Source exposure: binary-analysis; no external implementation source reused.
// Static177dc10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dc10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dc10*);
    virtual void release(Static177dc10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dc10*);
struct Static177dc10 {
    void* value;
    Static177dc10();
    ~Static177dc10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
