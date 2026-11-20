// Source exposure: binary-analysis; no external implementation source reused.
// Static17464a0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17464a0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17464a0*);
    virtual void release(Static17464a0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17464a0*);
struct Static17464a0 {
    void* value;
    Static17464a0();
    ~Static17464a0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
