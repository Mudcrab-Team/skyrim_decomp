// Source exposure: binary-analysis; no external implementation source reused.
// Static1780500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780500*);
    virtual void release(Static1780500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780500*);
struct Static1780500 {
    void* value;
    Static1780500();
    ~Static1780500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
