// Source exposure: binary-analysis; no external implementation source reused.
// Static179acf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179acf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179acf0*);
    virtual void release(Static179acf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179acf0*);
struct Static179acf0 {
    void* value;
    Static179acf0();
    ~Static179acf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
