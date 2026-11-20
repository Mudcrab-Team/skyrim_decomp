// Source exposure: binary-analysis; no external implementation source reused.
// Static175fb70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fb70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fb70*);
    virtual void release(Static175fb70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fb70*);
struct Static175fb70 {
    void* value;
    Static175fb70();
    ~Static175fb70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
