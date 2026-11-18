// Source exposure: binary-analysis; no external implementation source reused.
// Static1776460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776460*);
    virtual void release(Static1776460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776460*);
struct Static1776460 {
    void* value;
    Static1776460();
    ~Static1776460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
