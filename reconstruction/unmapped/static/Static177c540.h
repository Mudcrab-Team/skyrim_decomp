// Source exposure: binary-analysis; no external implementation source reused.
// Static177c540, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177c540;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177c540*);
    virtual void release(Static177c540*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177c540*);
struct Static177c540 {
    void* value;
    Static177c540();
    ~Static177c540() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
