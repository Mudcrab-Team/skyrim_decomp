// Source exposure: binary-analysis; no external implementation source reused.
// Static179e430, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e430;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e430*);
    virtual void release(Static179e430*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e430*);
struct Static179e430 {
    void* value;
    Static179e430();
    ~Static179e430() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
