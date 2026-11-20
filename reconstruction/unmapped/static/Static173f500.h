// Source exposure: binary-analysis; no external implementation source reused.
// Static173f500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f500*);
    virtual void release(Static173f500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f500*);
struct Static173f500 {
    void* value;
    Static173f500();
    ~Static173f500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
