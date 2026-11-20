// Source exposure: binary-analysis; no external implementation source reused.
// Static175ad50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175ad50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175ad50*);
    virtual void release(Static175ad50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175ad50*);
struct Static175ad50 {
    void* value;
    Static175ad50();
    ~Static175ad50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
