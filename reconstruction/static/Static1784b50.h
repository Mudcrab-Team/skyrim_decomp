// Source exposure: binary-analysis; no external implementation source reused.
// Static1784b50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784b50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784b50*);
    virtual void release(Static1784b50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784b50*);
struct Static1784b50 {
    void* value;
    Static1784b50();
    ~Static1784b50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
