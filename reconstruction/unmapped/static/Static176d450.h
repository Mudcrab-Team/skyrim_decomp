// Source exposure: binary-analysis; no external implementation source reused.
// Static176d450, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176d450;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176d450*);
    virtual void release(Static176d450*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176d450*);
struct Static176d450 {
    void* value;
    Static176d450();
    ~Static176d450() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
