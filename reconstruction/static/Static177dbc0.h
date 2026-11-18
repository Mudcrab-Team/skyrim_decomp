// Source exposure: binary-analysis; no external implementation source reused.
// Static177dbc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177dbc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177dbc0*);
    virtual void release(Static177dbc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177dbc0*);
struct Static177dbc0 {
    void* value;
    Static177dbc0();
    ~Static177dbc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
