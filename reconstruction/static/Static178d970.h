// Source exposure: binary-analysis; no external implementation source reused.
// Static178d970, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178d970;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178d970*);
    virtual void release(Static178d970*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178d970*);
struct Static178d970 {
    void* value;
    Static178d970();
    ~Static178d970() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
