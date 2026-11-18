// Source exposure: binary-analysis; no external implementation source reused.
// Static1759770, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1759770;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1759770*);
    virtual void release(Static1759770*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1759770*);
struct Static1759770 {
    void* value;
    Static1759770();
    ~Static1759770() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
