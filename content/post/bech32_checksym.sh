function bech32_checksum ()
{
    c=1
    for v_i in $@; do
	c0=$(( c >> 25 ))
	c=$(( ((c & 0x1ffffff) << 5) ^ v_i ))

	if ((c0 & 1)); then
	    c=$(( c ^ 0x3b6a57b2 ))
	fi
	if ((c0 & 2)); then
	    c=$(( c ^ 0x26508e6d ))
	fi
	if ((c0 & 4)); then
	    c=$(( c ^ 0x1ea119fa ))
	fi
	if ((c0 & 8)); then
	    c=$(( c ^ 0x3d4233dd ))
	fi
	if ((c0 & 16)); then
	    c=$(( c ^ 0x2a1462b3 ))
	fi
    done

    # mod=410305908
    mod=$(( c ^ 1 ))

    # checksum=(12 7 9 17 11 21)
    checksum=()
    for i in {0..5}; do
	checksum[$i]=$(( (mod >> 5 * (5-i)) & 31 ))
    done

    echo ${checksum[@]}
}
