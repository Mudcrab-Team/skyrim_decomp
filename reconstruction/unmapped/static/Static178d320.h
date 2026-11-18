// Source exposure: binary-analysis; no external implementation source reused.
// Static178d320, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d320;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d320*);
    virtual void release(Static178d320*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d320*);
struct Static178d320 {
    void* value;
    Static178d320();
    ~Static178d320() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
