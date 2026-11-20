// Source exposure: binary-analysis; no external implementation source reused.
// Static175c880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c880*);
    virtual void release(Static175c880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c880*);
struct Static175c880 {
    void* value;
    Static175c880();
    ~Static175c880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
