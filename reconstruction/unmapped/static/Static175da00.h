// Source exposure: binary-analysis; no external implementation source reused.
// Static175da00, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175da00;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175da00*);
    virtual void release(Static175da00*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175da00*);
struct Static175da00 {
    void* value;
    Static175da00();
    ~Static175da00() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
