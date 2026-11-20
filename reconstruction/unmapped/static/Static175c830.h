// Source exposure: binary-analysis; no external implementation source reused.
// Static175c830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175c830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175c830*);
    virtual void release(Static175c830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175c830*);
struct Static175c830 {
    void* value;
    Static175c830();
    ~Static175c830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
