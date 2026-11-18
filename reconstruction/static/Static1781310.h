// Source exposure: binary-analysis; no external implementation source reused.
// Static1781310, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1781310;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1781310*);
    virtual void release(Static1781310*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1781310*);
struct Static1781310 {
    void* value;
    Static1781310();
    ~Static1781310() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
