// Source exposure: binary-analysis; no external implementation source reused.
// Static177aa60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177aa60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177aa60*);
    virtual void release(Static177aa60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177aa60*);
struct Static177aa60 {
    void* value;
    Static177aa60();
    ~Static177aa60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
