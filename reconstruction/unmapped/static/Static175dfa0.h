// Source exposure: binary-analysis; no external implementation source reused.
// Static175dfa0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175dfa0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175dfa0*);
    virtual void release(Static175dfa0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175dfa0*);
struct Static175dfa0 {
    void* value;
    Static175dfa0();
    ~Static175dfa0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
