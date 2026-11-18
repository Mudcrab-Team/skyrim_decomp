// Source exposure: binary-analysis; no external implementation source reused.
// Static178c880, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c880;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c880*);
    virtual void release(Static178c880*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c880*);
struct Static178c880 {
    void* value;
    Static178c880();
    ~Static178c880() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
