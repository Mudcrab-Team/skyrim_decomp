// Source exposure: binary-analysis; no external implementation source reused.
// Static1767460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1767460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1767460*);
    virtual void release(Static1767460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1767460*);
struct Static1767460 {
    void* value;
    Static1767460();
    ~Static1767460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
