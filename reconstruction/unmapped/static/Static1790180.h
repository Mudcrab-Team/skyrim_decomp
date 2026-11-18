// Source exposure: binary-analysis; no external implementation source reused.
// Static1790180, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1790180;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1790180*);
    virtual void release(Static1790180*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1790180*);
struct Static1790180 {
    void* value;
    Static1790180();
    ~Static1790180() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
