// Source exposure: binary-analysis; no external implementation source reused.
// Static175fc10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175fc10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175fc10*);
    virtual void release(Static175fc10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175fc10*);
struct Static175fc10 {
    void* value;
    Static175fc10();
    ~Static175fc10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
