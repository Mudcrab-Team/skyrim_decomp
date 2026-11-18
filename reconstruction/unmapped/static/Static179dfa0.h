// Source exposure: binary-analysis; no external implementation source reused.
// Static179dfa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179dfa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179dfa0*);
    virtual void release(Static179dfa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179dfa0*);
struct Static179dfa0 {
    void* value;
    Static179dfa0();
    ~Static179dfa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
