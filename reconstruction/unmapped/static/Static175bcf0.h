// Source exposure: binary-analysis; no external implementation source reused.
// Static175bcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175bcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175bcf0*);
    virtual void release(Static175bcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175bcf0*);
struct Static175bcf0 {
    void* value;
    Static175bcf0();
    ~Static175bcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
