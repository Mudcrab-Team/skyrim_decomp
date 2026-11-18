// Source exposure: binary-analysis; no external implementation source reused.
// Static177c450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c450*);
    virtual void release(Static177c450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c450*);
struct Static177c450 {
    void* value;
    Static177c450();
    ~Static177c450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
