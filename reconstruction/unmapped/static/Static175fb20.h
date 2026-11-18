// Source exposure: binary-analysis; no external implementation source reused.
// Static175fb20, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fb20;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fb20*);
    virtual void release(Static175fb20*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fb20*);
struct Static175fb20 {
    void* value;
    Static175fb20();
    ~Static175fb20() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
