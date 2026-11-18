// Source exposure: binary-analysis; no external implementation source reused.
// Static1787d50, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787d50;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787d50*);
    virtual void release(Static1787d50*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787d50*);
struct Static1787d50 {
    void* value;
    Static1787d50();
    ~Static1787d50() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
