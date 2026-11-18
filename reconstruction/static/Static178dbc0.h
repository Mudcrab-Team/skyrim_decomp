// Source exposure: binary-analysis; no external implementation source reused.
// Static178dbc0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178dbc0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178dbc0*);
    virtual void release(Static178dbc0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178dbc0*);
struct Static178dbc0 {
    void* value;
    Static178dbc0();
    ~Static178dbc0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
