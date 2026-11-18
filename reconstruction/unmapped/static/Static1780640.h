// Source exposure: binary-analysis; no external implementation source reused.
// Static1780640, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780640;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780640*);
    virtual void release(Static1780640*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780640*);
struct Static1780640 {
    void* value;
    Static1780640();
    ~Static1780640() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
