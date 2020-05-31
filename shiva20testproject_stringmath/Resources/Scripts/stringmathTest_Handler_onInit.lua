--------------------------------------------------------------------------------
--  Handler.......... : onInit
--  Author........... :
--  Description...... :
--------------------------------------------------------------------------------

--------------------------------------------------------------------------------
function stringmathTest.onInit (  )
--------------------------------------------------------------------------------

    local res1 = sm.calculateSignedLong ( "890922592", "100000", sm.kAdd )
    local res2 = sm.calculateSignedLong ( "-890922592", "-100000", sm.kAdd )
    local res3 = sm.calculateUnsignedLong ( "-890922592", "-100000", sm.kAdd )
    local res5 = sm.calculateDouble ( "1.3", "2.4", sm.kAdd )
    local res6 = sm.calculateSignedLong ( "890922592000000000000000000000000000000000000000000", "10000100000000100001000000001000010000000010000100000000", sm.kAdd )
    local res7 = sm.calculateUnsignedLong ( "890922592000000000000000000000000000000000000000000", "10000100000000100001000000001000010000000010000100000000", sm.kAdd )
    local res8 = sm.calculateUnsignedLong ( "888888888888888888", "111111111111111111", sm.kAdd )
    local resP = sm.calculateUnsignedLong ( "100", "3", sm.kPow )
    local resO = sm.calculateUnsignedLong ( "100", "100", sm.kPow )

    log.message ( "big nums: " ..res1 ) -- additions of that size cause problems in Lua 5.0 (OK)
    log.message ( "negative: " ..res2 ) -- negative (OK)
    log.message ( "nonsense: " ..res3 ) -- produces nonsense because it does not accept negative values (OK)
    log.message ( "std double: " ..res5 ) -- double (OK)
    log.message ( "signed overflow: " ..res6 ) -- produces nonsense (ERROR)
    log.message ( "unsigned overflow: " ..res7 ) -- gets cut at uint_max (OK)
    log.message ( "really big nums: " ..res8 ) -- works as long as you keep within the limits of long (OK)
    log.message ( "std power: " ..resP ) -- works as long as you keep within the limits of long (OK)
    log.message ( "power overflow: " ..resO ) -- gives a 0 (OK)


    application.quit ( )

--------------------------------------------------------------------------------
end
--------------------------------------------------------------------------------
