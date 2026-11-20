// Source exposure: binary-analysis; no external implementation source reused.
// Static177aa10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177aa10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177aa10*);
    virtual void release(Static177aa10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177aa10*);
struct Static177aa10 {
    void* value;
    Static177aa10();
    ~Static177aa10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
