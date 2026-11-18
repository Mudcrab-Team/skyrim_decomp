// Source exposure: binary-analysis; no external implementation source reused.
// Static1780460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1780460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1780460*);
    virtual void release(Static1780460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1780460*);
struct Static1780460 {
    void* value;
    Static1780460();
    ~Static1780460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
